template <typename InputIterator>
void    Span::addRange(InputIterator first, InputIterator last) {
    while (first != last)
    {
        addNumber(*first);
        first++;
    }
}