template<class FwdIt, class Compare = std::less<>>
void selection_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const selection = std::min_element(it, last, cmp);
        std::iter_swap(selection, it); 
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}
