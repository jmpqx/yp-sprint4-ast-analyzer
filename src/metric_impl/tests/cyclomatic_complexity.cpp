#include "metric_impl/cyclomatic_complexity.hpp"
#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

using CyclomaticComplexityFixture = MetricFixture<CyclomaticComplexityMetric>;

TEST_P(CyclomaticComplexityFixture, Test) {
    const auto &[func_name, file_name, expected] = GetParam();
    Init(file_name);
    ASSERT_EQ(GetResult(func_name), std::get<int>(expected));
}

INSTANTIATE_TEST_SUITE_P(CyclomaticComplexityTests, CyclomaticComplexityFixture, testing::Values(
    TestCase{"Func_comments", "comments.py", 1},
    TestCase{"testIf", "if.py", 2},
    TestCase{"TestLoops", "loops.py", 4},
    TestCase{"Testnestedif", "nested_if.py", 4},
    TestCase{"teSt_ternary", "ternary.py", 3},
    TestCase{"Try_Exceptions", "exceptions.py", 4},
    TestCase{"test_Match_case", "match_case.py", 4},
    TestCase{"__test_multiparameters__", "many_parameters.py", 2},
    TestCase{"testmultiline", "many_lines.py", 2},
    TestCase{"test_simple", "simple.py", 2}
));

}  // namespace analyzer::metric::metric_impl
