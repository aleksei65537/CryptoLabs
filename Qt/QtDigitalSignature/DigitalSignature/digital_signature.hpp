# pragma once

#include "EGCD/egcd.hpp"
#include <openssl/md5.h>
#include <string>
#include <iterator>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/random_device.hpp>
#include <sstream>
#include <exception>

namespace ds {

    template <size_t key_size = 2048, typename T = boost::multiprecision::mpz_int>
    class RSA;
    
    template <size_t key_size, typename T>
    std::string sign(const std::string&, RSA<key_size, T>&);
    
    template <size_t key_size, typename T>
    bool verify(const std::string&, const std::string&, RSA<key_size, T>&);


    template <size_t key_size, typename T>
    class RSA {
        private:
            friend std::string sign<key_size, T>(const std::string&, 
                                                 RSA<key_size,T>&);
            friend bool verify<key_size, T>(const std::string&,
                               const std::string&, RSA<key_size, T>&); 
            std::string get_asn1_len(const std::string&) const;
            std::string get_asn1_int(const std::string&) const;
            std::string export_privkey_to_hex() const;
            std::string export_pubkey_to_hex() const;
            std::string hex_str(const std::string&) const;
            std::string ascii_str(const std::string&) const;
            std::string hex_to_base64(const std::string&) const;
            std::string base64_to_hex(const std::string&) const;
            size_t hex_to_size_t(char) const;
            size_t b64_to_size_t(char) const;
            size_t set_asn1_len(const std::string&) const;
            size_t set_asn1_int(const std::string&, T&);
            void import_privkey_from_hex(const std::string);
            void import_pubkey_from_hex(const std::string);

            T get_prime() const;
            const std::string b64_map =
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx"
                 "yz0123456789+/";
            const std::string hex_map =
                "0123456789abcdef";
        public:
            T modulus;
            T public_exponent;
            T private_exponent;
            T prime_1;
            T prime_2;
            T exponent_1;
            T exponent_2;
            T coefficient;
            T encrypt(T, bool = true);
            T decrypt(T, bool = true);
            std::string encrypt(const std::string&, bool = true);
            std::string decrypt(const std::string&, bool = true);
            void generate ();
            void export_privkey_to_der(std::ostream&) const;
            void export_privkey_to_pem(std::ostream&) const;
            void export_pubkey_to_der(std::ostream&) const;
            void export_pubkey_to_pem(std::ostream&) const;
            void import_privkey_from_der(std::istream&);
            void import_privkey_from_pem(std::istream&);
            void import_privkey_from_pem(const std::string&);
            void import_pubkey_from_der(std::istream&);
            void import_pubkey_from_pem(std::istream&);
            void import_pubkey_from_pem(const std::string&);
            RSA() : public_exponent(65537) { }
    };

    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::hex_str(const std::string& data) const {
        std::string s(data.size() * 2, ' ');

        for (size_t i = 0; i < data.size(); ++i) {
            s[2 * i]     = hex_map[(data[i] & 0xF0) >> 4];
            s[2 * i + 1] = hex_map[data[i] & 0x0F];
        }

        return s;
    }

    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::ascii_str(const std::string& shex) const {
        std::string copy = shex;
        copy = copy.size() % 2 == 0 ? copy : "0" + copy;
        std::string ascii;
        int tmp;

        for (size_t i = 0; i < copy.size(); i += 2) {
            std::stringstream ss(copy.substr(i, 2));
            ss >> std::hex >> tmp;
            ascii.push_back(static_cast<char>(tmp));
        }

        return ascii;
    }

    // set value len in hex chars
    template<size_t key_size, typename T>
    size_t RSA<key_size, T>::set_asn1_len (const std::string& shex) const {
        std::stringstream ss;
        size_t tag = std::stoull(shex.substr(0, 2), 0, 16);
        size_t len = 0;

        if (tag <= 0x7F) {
            len = tag;
        } else {
                len = std::stoull(shex.substr(2, 2 * (tag - 0x80)), 0, 16);
        }

        // hex lengt = 2 * byte length
        return len * 2;
    }


    template<size_t key_size, typename T>
    size_t RSA<key_size, T>::set_asn1_int (const std::string& shex,
                                           T& big_int) {
        std::stringstream ss;
        size_t val_len;
        size_t len_len;
        // length of tag + length of length tag
        size_t tag_len = 4;
        size_t tag;

        // is it an integer?
        if (shex.substr(0, 2) == "02") {
            // get tag value first
            tag = std::stoull(shex.substr(2, 2), 0, 16);
            // get length field length
            len_len = tag <= 0x7F ? 0 : tag - 0x80;
            // hex == bute * 2
            len_len *= 2;
            // get value length
            val_len = set_asn1_len(shex.substr(2, shex.size() - 2));
            // tag_len + len_len + 2
            big_int = T("0x" + shex.substr(tag_len + len_len, val_len));
        } else {

            throw std::invalid_argument("The key is corrupted (INT)");
        }

        return tag_len + len_len + val_len;
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_pubkey_from_hex(const std::string shex) {
        std::stringstream ss;

        if(shex.substr(0, 2) == "30") {
            // find out the length of value
            size_t seq_len = set_asn1_len(shex.substr(2, shex.size() - 2));
            size_t position = shex.size() - seq_len;
            position += set_asn1_int(
                    shex.substr(position, shex.size() - position), modulus);
            set_asn1_int(shex.substr(position, shex.size() - position),
                                    public_exponent);
        } else {
            throw std::invalid_argument("The key is corrupted (SEQ)");
        }
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_privkey_from_hex(const std::string shex) {
        std::stringstream ss;

        if(shex.substr(0, 2) == "30") {
            size_t seq_len = set_asn1_len(shex.substr(2, shex.size() - 2));
            size_t position = shex.size() - seq_len;

            if (shex.substr(position, 6) == "020100") {
                position += 6;
            } else {
                throw std::invalid_argument("The key is corrupted (VERSION)");
            }

            position += set_asn1_int(shex.substr(
                        position, shex.size() - position), modulus);
            position += set_asn1_int(shex.substr(
                        position, shex.size() - position), public_exponent);
            position += set_asn1_int(shex.substr(
                        position, shex.size() - position), private_exponent);
            position += set_asn1_int(shex.substr(
                        position, shex.size() - position), prime_1);
            position += set_asn1_int(shex.substr(
                        position, shex.size() - position), prime_2);
            position += set_asn1_int(shex.substr(
                        position, shex.size() - position), exponent_1);
            position += set_asn1_int(shex.substr(
                        position, shex.size() - position), exponent_2);
            set_asn1_int(shex.substr(position, shex.size() - position),
                                     coefficient);
        } else {
            throw std::invalid_argument("The key is corrupted (SEQ)");
        }
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_privkey_from_der(std::istream& is) {
        std::string shex;

        is.seekg (0, is.end);
        size_t length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];

        is.read (buffer,length);

        std::string tmp;

        for (size_t i = 0; i < length; i++) {
            tmp.push_back(buffer[i]);
        }

        delete[] buffer;
        shex = hex_str(tmp);
        import_privkey_from_hex(shex);
    }


    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_pubkey_from_der (std::istream& is) {
        std::string shex;

        is.seekg (0, is.end);
        size_t length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];

        is.read (buffer,length);

        std::string tmp;

        for (size_t i = 0; i < length; i++) {
            tmp.push_back(buffer[i]);
        }

        delete[] buffer;
        shex = hex_str(tmp);
        import_pubkey_from_hex(shex);
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_privkey_from_pem (const std::string& s) {
        std::string shex;

        std::string tmp = s;

        // remove white space

        tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());

        if (tmp.starts_with("-----BEGINRSAPRIVATEKEY-----") &&
            tmp.ends_with("-----ENDRSAPRIVATEKEY-----")) {
            std::string shex = base64_to_hex(tmp.substr(28, tmp.size() - 54));
            import_privkey_from_hex(shex);
        } else {
            throw std::invalid_argument("The key is corrupted (SIGNATURE)");
        }
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_pubkey_from_pem (const std::string& s) {

        std::string tmp = s;
        
        // remove white space

        tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());

        if (tmp.starts_with("-----BEGINRSAPUBLICKEY-----") &&
            tmp.ends_with("-----ENDRSAPUBLICKEY-----")) {
            std::string shex = base64_to_hex(tmp.substr(27, tmp.size() - 52));
            import_pubkey_from_hex(shex);
        } else {
            throw std::invalid_argument("The key is corrupted (SIGNATURE)");
        }
    }


    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_privkey_from_pem (std::istream& is) {
        std::string shex;

        is.seekg (0, is.end);
        size_t length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];

        is.read (buffer,length);

        std::string tmp;

        for (size_t i = 0; i < length; i++) {
            tmp.push_back(buffer[i]);
        }

        delete[] buffer;
        
        // remove white space

        tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());

        if (tmp.starts_with("-----BEGINRSAPRIVATEKEY-----") &&
            tmp.ends_with("-----ENDRSAPRIVATEKEY-----")) {
            std::string shex = base64_to_hex(tmp.substr(28, tmp.size() - 54));
            import_privkey_from_hex(shex);
        } else {
            throw std::invalid_argument("The key is corrupted (SIGNATURE)");
        }
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::import_pubkey_from_pem (std::istream& is) {
        std::string shex;

        is.seekg (0, is.end);
        size_t length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];

        is.read (buffer,length);

        std::string tmp;

        for (size_t i = 0; i < length; i++) {
            tmp.push_back(buffer[i]);
        }

        delete[] buffer;
        
        // remove white space

        tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());

        if (tmp.starts_with("-----BEGINRSAPUBLICKEY-----") &&
            tmp.ends_with("-----ENDRSAPUBLICKEY-----")) {
            std::string shex = base64_to_hex(tmp.substr(27, tmp.size() - 52));
            import_pubkey_from_hex(shex);
        } else {
            throw std::invalid_argument("The key is corrupted (SIGNATURE)");
        }
    }

    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::get_asn1_len(const std::string& shex) const {
        std::stringstream ss;
        size_t size = shex.size() / 2;

        if (0x00 <= size && size <= 0x7F) {
            ss << std::hex << std::setfill('0') << std::setw(2) << size;
            return ss.str();
        } else if (0x80 <= size && size <= 0xFF) {
            ss << std::hex << 0x81 << std::setfill('0') << std::setw(2) << size;
            return ss.str();
        } else {
            size_t prefix = 0x82;
            size_t min = 0x100;
            size_t max = 0xFFFF;

            while(true) {
                if (min <= size && size <= max) {
                    break;
                } else {
                    ++prefix;
                    min <<= 2;
                    max <<= 2;
                    max += 0xFF;
                }
            }

            ss << std::hex << prefix;
            ss << std::hex <<
                std::setfill('0') << std::setw((prefix - 0x80) * 2) << size;
            return ss.str();
        }
    }


    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::get_asn1_int(const std::string& s) const {
        std::string val = s;

        if (val.size() % 2 != 0) {
            val = "0" + val;
        }

        int signed_byte = std::stoi(s.substr(0, 2), 0, 16);

        if (signed_byte > 0x7F) {
            val = "00" + val;
        }

        std::string len = get_asn1_len(val);

        return "02" + len + val;
    }

    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::export_privkey_to_hex() const {
        std::stringstream ss;
        std::string shex;

        // coefficient TLV
        ss << std::hex << coefficient;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // exponent_2 TLV
        ss << std::hex << exponent_2;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // exponent_1 TLV
        ss << std::hex << exponent_1;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // prime_2 TLV
        ss << std::hex << prime_2;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // prime_1 TLV
        ss << std::hex << prime_1;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // private_exponent TLV
        ss << std::hex << private_exponent;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // public_exponent TLV
        ss << std::hex << public_exponent;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // modulus TLV
        ss << std::hex << modulus;
        shex.insert(0, get_asn1_int("00" + ss.str()));
        ss.str(std::string());

        // version TLV
        shex.insert(0, "020100");

        // sequence TLV
        shex.insert(0, get_asn1_len(shex));
        shex.insert(0, "30");

        return shex;
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::export_privkey_to_der(std::ostream& os) const {
        std::string shex = export_privkey_to_hex();
        std::string ascii = ascii_str(shex);
        os.write(ascii.c_str(), ascii.size());
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::export_privkey_to_pem(std::ostream& os) const {
        os << "-----BEGIN RSA PRIVATE KEY-----";

        std::string b64_str = hex_to_base64(export_privkey_to_hex());

        for (size_t i = 0; i < b64_str.size(); i++) {

            if(i % 64 != 0) {
                os << b64_str[i];
            } else {
                os << std::endl << b64_str[i];
            }
        }

        os << std::endl;
        os << "-----END RSA PRIVATE KEY-----" << std::endl;
    }

    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::export_pubkey_to_hex() const {
        std::stringstream ss;
        std::string shex;

        // public_exponent TLV
        ss << std::hex << public_exponent;
        shex.insert(0, get_asn1_int(ss.str()));
        ss.str(std::string());

        // modulus TLV
        ss << std::hex << modulus;
        shex.insert(0, get_asn1_int("00" + ss.str()));
        ss.str(std::string());

        // sequence TLV
        shex.insert(0, get_asn1_len(shex));
        shex.insert(0, "30");

        return shex;
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::export_pubkey_to_der(std::ostream& os) const {
        std::string shex = export_pubkey_to_hex();
        std::string ascii = ascii_str(shex);
        os.write(ascii.c_str(), ascii.size());
    }

    template<size_t key_size, typename T>
    void RSA<key_size, T>::export_pubkey_to_pem(std::ostream& os) const {
        os << "-----BEGIN RSA PUBLIC KEY-----";

        std::string b64_str = hex_to_base64(export_pubkey_to_hex());

        for (size_t i = 0; i < b64_str.size(); i++) {

            if(i % 64 != 0) {
                os << b64_str[i];
            } else {
                os << std::endl << b64_str[i];
            }
        }

        os << std::endl;
        os << "-----END RSA PUBLIC KEY-----" << std::endl;
    }

    // Calculate hex character index
    template<size_t key_size, typename T>
    size_t RSA<key_size, T>::hex_to_size_t(char h) const {

        if(std::isdigit(static_cast<int>(h))) {
            return h - '0';
        } else {
            return std::tolower(static_cast<int>(h)) - 'a' + 10;
        }
    }

    // Calculate base64 character index
    template<size_t key_size, typename T>
    size_t RSA<key_size, T>::b64_to_size_t(char b) const {
        return b64_map.find(b);
    }

    // Encode hex to base64
    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::hex_to_base64(const std::string& s) const {
        std::string base64_string;
        size_t tmp = 0;
        std::string hex_string = s;
        long long padding = hex_string.size() % 3 == 0
                               ? 0
                               : 3 - hex_string.size() % 3;

        for (long long i = 0; i < padding; i++) {
           hex_string.push_back(hex_map[0]);
        }

        for (size_t i = 0; i < hex_string.size(); i+=3) {
            tmp = 0;

            for (size_t j = 0; j < 3; j++) {
                tmp <<= 4;
                tmp += hex_to_size_t(hex_string[i + j]);
            }

            for (int j = 1; j >= 0; j--) {
                base64_string.push_back(b64_map[(tmp >> 6 * j) & 0x3F]);
            }
        }

        if (padding) {

            for (long long i = 0; i < padding - 1; i++) {
                base64_string.pop_back();
            }

            for (long long i = 0; i < 3 - padding; i++) {
                base64_string.push_back('=');
            }
        }

        return base64_string;
    }

    // Decode base64 to hex
    template<size_t key_size, typename T>
    std::string RSA<key_size, T>::base64_to_hex(const std::string& s) const {
        std::string hex_string;
        size_t tmp = 0;
        std::string base64_string = s;
        auto equal_count =
            std::count(base64_string.begin(), base64_string.end(), '=');
        auto padding = 3 - equal_count;

        for (long long i = 0; i < equal_count; i++) {
            base64_string.pop_back();
        }

        if (equal_count != 0) {

            for (long long i = 0; i < padding - 1; i++) {
                base64_string.push_back(b64_map[0]);
            }
        }

        for (size_t i = 0; i < base64_string.size(); i += 2) {
            tmp = 0;

            for (size_t j = 0; j < 2; j++) {
                tmp <<= 6;
                tmp += b64_to_size_t(base64_string[i + j]);
            }

            for (long long j = 2; j >= 0; j--) {
                hex_string.push_back(hex_map[(tmp >> 4 * j) & 0x0F]);
            }
        }

        if (equal_count) {

            for (long long i = 0; i < padding; i++) {
                hex_string.pop_back();
            }
        }

        return hex_string;
    }

    // Outputs a prime number that is guaranteed to be in the ranger of
    // 2 ** (key_size / 2) <= prime <  2 ** (key_size / 2 + 1)
    template <size_t key_size, typename T>
    T RSA<key_size, T>::get_prime() const {
        using namespace boost::random;
        using namespace boost::multiprecision;
        T min = T(6074001000) << (key_size / 2 - 33);
        random_device rng; // real random numbers
        independent_bits_engine<mt11213b, key_size / 2, T> big_rng(rng);
        T prime;

        do {
            prime = big_rng() | (T(1) << (key_size / 2 - 1));
        } while (!(prime >= min) || !miller_rabin_test(prime, 32));

        return prime;
    }

    // Generates public and private keys
    template <size_t key_size, typename T>
    void RSA<key_size, T>::generate() {
        T p, q, phi;

        do {
            p = get_prime();
            q = get_prime();
            phi = (p - 1) * (q - 1);
        } while (boost::multiprecision::abs(p - q) >> 64 == T(0) ||
                boost::multiprecision::gcd(phi, public_exponent) != 1);

        private_exponent = EGCD<T>(phi, public_exponent).t;

        private_exponent < 0
            ? private_exponent = private_exponent + phi
            : private_exponent %= phi;

        modulus = p * q;
        prime_1 = p;
        prime_2 = q;
        exponent_1 = private_exponent % (p - 1);
        exponent_2 = private_exponent % (q - 1);
        coefficient = EGCD<T>(p, q).t;
        coefficient < 0
            ? coefficient += p
            : coefficient %= p;
    }

    // Encrypts given message with default key
    template <size_t key_size, typename T>
    T RSA<key_size, T>::encrypt(T m, bool use_pub_key) {
        return use_pub_key == true
            ? boost::multiprecision::powm(
                    m, this->public_exponent, this->modulus)
            : boost::multiprecision::powm(
                    m, this->private_exponent, this->modulus);
    }

    template <size_t key_size, typename T>
    std::string RSA<key_size, T>::encrypt(const std::string& message,
                                                 bool use_pub_key) {
            using boost::multiprecision::mpz_int;
            std::string shex = hex_str(message);
            std::stringstream ss;
            T imessage;
            ss << shex;
            ss >> std::hex >> imessage;
            T ichiper = use_pub_key == true
            ? boost::multiprecision::powm(
                    imessage, this->public_exponent, this->modulus)
            : boost::multiprecision::powm(
                    imessage, this->private_exponent, this->modulus);
            ss.clear();
            ss.str("");
            std::string chiper;
            ss << std::hex << ichiper;
            ss >> chiper;
            return hex_to_base64(chiper);
    }

    // Decrypts given message with default key
    template <size_t key_size, typename T>
    T RSA<key_size, T>::decrypt(T m, bool use_priv_key) {
        return use_priv_key == true
            ? boost::multiprecision::powm(
                    m, this->private_exponent, this->modulus)
            : boost::multiprecision::powm(
                    m, this->public_exponent, this->modulus);
    }



    template <size_t key_size, typename T>
    std::string RSA<key_size, T>::decrypt(const std::string& chiper,
                                          bool use_priv_key) {
            std::string shex = base64_to_hex(chiper);
            std::stringstream ss;
            T ichiper;
            ss << shex;
            ss >> std::hex >> ichiper;
            T imessage = use_priv_key == true
            ? boost::multiprecision::powm(
                    ichiper, this->private_exponent, this->modulus)
            : boost::multiprecision::powm(
                    ichiper, this->public_exponent, this->modulus);
            ss.clear();
            ss.str("");
            std::string message;
            ss << imessage;
            ss >> message;
            return ascii_str(message);
    }

    template <size_t key_size, typename T>
    std::string sign(const std::string& message, RSA<key_size, T>& rsa) {
        auto hash = MD5((unsigned char*)message.c_str(), message.size(), NULL);
        std::string tmp((char*)hash, MD5_DIGEST_LENGTH);
        std::string hex = rsa.hex_str(tmp);
        std::string signatue = rsa.encrypt(hex, false);
        return signatue;
    }


    template <size_t key_size, typename T>
    bool verify(const std::string& message, 
                       const std::string& signature, RSA<key_size, T>& rsa) {

        std::string s = signature;
        s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
        std::string decrypted = rsa.decrypt(s, false);
        
        for (size_t i = 0; decrypted.size() < 32; i++) {
            decrypted = "0" + decrypted;
        }

        auto hash = MD5((unsigned char*)message.c_str(), message.size(), NULL);
        std::string tmp((char*)hash, MD5_DIGEST_LENGTH);
        std::string hex = rsa.hex_str(tmp);

        if(hex == decrypted) {
            return true;
        } else {
            return false;
        }
    }
}
