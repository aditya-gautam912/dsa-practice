import pytest
from solution_longest_substring import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.lengthOfLongestSubstring("abcabcbb") == 3


def test_example_2(solution):
    assert solution.lengthOfLongestSubstring("bbbbb") == 1


def test_example_3(solution):
    assert solution.lengthOfLongestSubstring("pwwkew") == 3


def test_empty_string(solution):
    assert solution.lengthOfLongestSubstring("") == 0


def test_single_character(solution):
    assert solution.lengthOfLongestSubstring(" ") == 1


def test_all_unique(solution):
    assert solution.lengthOfLongestSubstring("abcdef") == 6


def test_with_digits_and_symbols(solution):
    assert solution.lengthOfLongestSubstring("a1b2c3") == 6


def test_repeating_at_distance(solution):
    assert solution.lengthOfLongestSubstring("dvdf") == 3
