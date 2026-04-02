#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitocinExchange {

private:
    std::map<std::string, double>   _rates;

    BitocinExchange(void);

    bool        isLeapYear(int year) const;
    bool        isValidDate(const std::string& date) const;
    bool        isValidValue(const std::string& valueStr, double& value) const;
    std::string trim(const std::string& str) const;
    double      getRateForDate(const std::string& date) const;

public:
    BitocinExchange(const std::string& csvFile);
    BitocinExchange(const BitocinExchange& copy);
    BitocinExchange&    operator=(const BitocinExchange& copy);
    ~BitocinExchange(void);

    void    loadDatabase(const std::string& csvFile);
    void    processInputFile(const std::string& inputFile) const;

};

#endif