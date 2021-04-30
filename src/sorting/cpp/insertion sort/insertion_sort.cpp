template<class FwdIt, class Compare = std::less<>>
void insertion_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const insertion = std::upper_bound(first, it, *it, cmp);
        std::rotate(insertion, it, std::next(it)); 
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}
