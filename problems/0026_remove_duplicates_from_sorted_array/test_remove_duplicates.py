import pytest
from solution_remove_duplicates import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    nums = [1, 1, 2]
    k = solution.removeDuplicates(nums)
    assert k == 2
    assert nums[:k] == [1, 2]


def test_example_2(solution):
    nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    k = solution.removeDuplicates(nums)
    assert k == 5
    assert nums[:k] == [0, 1, 2, 3, 4]


def test_single_element(solution):
    nums = [5]
    k = solution.removeDuplicates(nums)
    assert k == 1
    assert nums[:k] == [5]


def test_all_unique(solution):
    nums = [1, 2, 3, 4, 5]
    k = solution.removeDuplicates(nums)
    assert k == 5
    assert nums[:k] == [1, 2, 3, 4, 5]


def test_all_same(solution):
    nums = [7, 7, 7, 7]
    k = solution.removeDuplicates(nums)
    assert k == 1
    assert nums[:k] == [7]


def test_negative_numbers(solution):
    nums = [-3, -3, -1, 0, 0, 2]
    k = solution.removeDuplicates(nums)
    assert k == 4
    assert nums[:k] == [-3, -1, 0, 2]
