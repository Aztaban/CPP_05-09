#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcpet>

class Span {

private:
    unsigned int	    _maxSize;
    std::vector<int>    _numbers;

public:
    Span(void);
    Span(unsigned int N);
    Span(const Span& copy);

    Span& operator=(const Span& copy);

    ~Span(void);

    void    addNumber(int number);
    int		shortestSpan(void) const;
    int		longestSpan(void) const;

    template <typename InputIterator>
    void    addRange(InputIterator first, InputIterator last);

    class   FullSpanException : public std::exception {
        public:
            virtual const char* what() const throw();
    }

    class   NoSpanFoundException : public std::exception {
        public:
            virtual const char* what() const throw();
    }

    #include "Span.tpp"
};

#endif