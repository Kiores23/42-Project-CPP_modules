#ifndef BTC_HPP
# define BTC_HPP

# include <iostream>
# include <map>

class	Btc {
    private:
        std::map<std::string, float>	_Data;
        void    addData(std::string & line);
        void    printInput(std::string & line);

    public:
        Btc();
        Btc(const Btc & other);
        ~Btc();
        Btc & operator=(const Btc & other);

        void    BtcCheck(const std::string & fileName);
};

#endif
