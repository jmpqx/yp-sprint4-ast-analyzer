#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

using CountParametersFixture = MetricFixture<CountParametersMetric>;

TEST_P(CountParametersFixture, Test) {
    const auto &[func_name, file_name, expected] = GetParam();
    Init(file_name);
    ASSERT_EQ(GetResult(func_name), std::get<int>(expected));
}

INSTANTIATE_TEST_SUITE_P(CountParametersTests, CountParametersFixture, testing::Values(
    TestCase{"Func_comments", "comments.py", 3},
    TestCase{"testIf", "if.py", 1},
    TestCase{"TestLoops", "loops.py", 1},
    TestCase{"Testnestedif", "nested_if.py", 2},
    TestCase{"teSt_ternary", "ternary.py", 1},
    TestCase{"Try_Exceptions", "exceptions.py", 0},
    TestCase{"test_Match_case", "match_case.py", 1},
    TestCase{"__test_multiparameters__", "many_parameters.py", 5},
    TestCase{"testmultiline", "many_lines.py", 0},
    TestCase{"test_simple", "simple.py", 0}
));

}  // namespace analyzer::metric::metric_impl
