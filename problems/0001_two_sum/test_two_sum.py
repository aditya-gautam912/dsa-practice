import pytest
from solution_two_sum import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.twoSum([2, 7, 11, 15], 9) == [0, 1]


def test_example_2(solution):
    assert solution.twoSum([3, 2, 4], 6) == [1, 2]


def test_example_3(solution):
    assert solution.twoSum([3, 3], 6) == [0, 1]


def test_negative_numbers(solution):
    assert solution.twoSum([-1, -2, -3, -4, -5], -8) == [2, 4]


def test_with_zero(solution):
    assert solution.twoSum([0, 4, 3, 0], 0) == [0, 3]


def test_large_numbers(solution):
    assert solution.twoSum([10**9, -10**9], 0) == [0, 1]
