import pytest
from solution_3sum import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    result = solution.threeSum([-1, 0, 1, 2, -1, -4])
    assert sorted(result) == sorted([[-1, -1, 2], [-1, 0, 1]])


def test_example_2(solution):
    assert solution.threeSum([0, 1, 1]) == []


def test_example_3(solution):
    assert solution.threeSum([0, 0, 0]) == [[0, 0, 0]]


def test_no_triplet(solution):
    assert solution.threeSum([1, 2, -2, -1]) == []


def test_all_negative(solution):
    assert solution.threeSum([-5, -4, -3, -2, -1]) == []


def test_all_positive(solution):
    assert solution.threeSum([1, 2, 3, 4, 5]) == []


def test_multiple_solutions(solution):
    result = solution.threeSum([-2, -1, 0, 1, 2])
    expected = [[-2, 0, 2], [-1, 0, 1]]
    assert sorted(result) == sorted(expected)


def test_duplicates_in_input(solution):
    result = solution.threeSum([-1, -1, -1, 0, 1, 1, 1])
    expected = [[-1, 0, 1]]
    assert sorted(result) == sorted(expected)
