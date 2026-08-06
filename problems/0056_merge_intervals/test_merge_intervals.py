import pytest
from solution_merge_intervals import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.merge([[1, 3], [2, 6], [8, 10], [15, 18]]) == [[1, 6], [8, 10], [15, 18]]


def test_example_2(solution):
    assert solution.merge([[1, 4], [4, 5]]) == [[1, 5]]


def test_no_overlap(solution):
    assert solution.merge([[1, 2], [3, 4], [5, 6]]) == [[1, 2], [3, 4], [5, 6]]


def test_all_overlap(solution):
    assert solution.merge([[1, 4], [2, 5], [3, 6]]) == [[1, 6]]


def test_contained_intervals(solution):
    assert solution.merge([[1, 10], [2, 3], [4, 5]]) == [[1, 10]]


def test_single_interval(solution):
    assert solution.merge([[1, 3]]) == [[1, 3]]


def test_unsorted_input(solution):
    assert solution.merge([[3, 6], [1, 2], [4, 5]]) == [[1, 2], [3, 6]]
