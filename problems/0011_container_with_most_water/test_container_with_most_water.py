import pytest
from solution_container_with_most_water import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49


def test_example_2(solution):
    assert solution.maxArea([1, 1]) == 1


def test_increasing(solution):
    assert solution.maxArea([1, 2, 3, 4, 5]) == 6


def test_decreasing(solution):
    assert solution.maxArea([5, 4, 3, 2, 1]) == 6


def test_same_height(solution):
    assert solution.maxArea([4, 4, 4, 4]) == 12


def test_zero_height(solution):
    assert solution.maxArea([0, 2, 0, 2, 0]) == 4


def test_large_gap(solution):
    assert solution.maxArea([1, 100, 1, 1, 1, 1, 1, 100, 1]) == 600
