#include <cassert>

[[maybe_unused]] static constexpr void test_for_assert() noexcept {
    constexpr auto side_effect = 1;
    static_assert(
        [] {
            int i = 0;
            assert(i++ == 0);  // NOLINT
            return i;
        }() == side_effect,
        "Assertions are disabled but are required for fuzz testing");
}
