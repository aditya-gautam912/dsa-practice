import pytest
from solution_next_permutation import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    nums = [1, 2, 3]
    solution.nextPermutation(nums)
    assert nums == [1, 3, 2]


def test_example_2(solution):
    nums = [3, 2, 1]
    solution.nextPermutation(nums)
    assert nums == [1, 2, 3]


def test_example_3(solution):
    nums = [1, 1, 5]
    solution.nextPermutation(nums)
    assert nums == [1, 5, 1]


def test_repeated_digits(solution):
    nums = [1, 5, 1]
    solution.nextPermutation(nums)
    assert nums == [5, 1, 1]


def test_two_elements(solution):
    nums = [1, 2]
    solution.nextPermutation(nums)
    assert nums == [2, 1]


def test_two_elements_descending(solution):
    nums = [2, 1]
    solution.nextPermutation(nums)
    assert nums == [1, 2]


def test_single_element(solution):
    nums = [1]
    solution.nextPermutation(nums)
    assert nums == [1]
