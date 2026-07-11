import pytest
from solution_3sum_closest import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.threeSumClosest([-1, 2, 1, -4], 1) == 2


def test_example_2(solution):
    assert solution.threeSumClosest([0, 0, 0], 1) == 0


def test_exact_match(solution):
    assert solution.threeSumClosest([1, 2, 3, 4], 6) == 6


def test_negative_target(solution):
    assert solution.threeSumClosest([-5, -2, -1, 0], -8) == -8


def test_all_positive(solution):
    assert solution.threeSumClosest([1, 2, 3, 4, 5], 10) == 10


def test_large_values(solution):
    assert solution.threeSumClosest([1000, 999, 998], 3000) == 2997


def test_closest_is_not_exact(solution):
    result = Solution().threeSumClosest([1, 1, 1, 0], -100)
    assert result == 2
