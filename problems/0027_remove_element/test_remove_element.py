import pytest
from solution_remove_element import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    nums = [3, 2, 2, 3]
    k = solution.removeElement(nums, 3)
    assert k == 2
    assert sorted(nums[:k]) == [2, 2]


def test_example_2(solution):
    nums = [0, 1, 2, 2, 3, 0, 4, 2]
    k = solution.removeElement(nums, 2)
    assert k == 5
    assert sorted(nums[:k]) == [0, 0, 1, 3, 4]


def test_remove_none(solution):
    nums = [1, 2, 3]
    k = solution.removeElement(nums, 4)
    assert k == 3
    assert sorted(nums[:k]) == [1, 2, 3]


def test_remove_all(solution):
    nums = [1, 1, 1]
    k = solution.removeElement(nums, 1)
    assert k == 0


def test_empty_array(solution):
    nums = []
    k = solution.removeElement(nums, 0)
    assert k == 0


def test_single_remove(solution):
    nums = [5]
    k = solution.removeElement(nums, 5)
    assert k == 0
