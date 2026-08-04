import pytest
from solution_group_anagrams import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    result = solution.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    assert sorted([sorted(group) for group in result]) == sorted(
        [sorted(["bat"]), sorted(["nat", "tan"]), sorted(["ate", "eat", "tea"])]
    )


def test_example_2(solution):
    assert solution.groupAnagrams([""]) == [[""]]


def test_example_3(solution):
    assert solution.groupAnagrams(["a"]) == [["a"]]


def test_all_anagrams(solution):
    result = solution.groupAnagrams(["abc", "bca", "cab"])
    assert [sorted(group) for group in result] == [sorted(["abc", "bca", "cab"])]


def test_no_anagrams(solution):
    result = solution.groupAnagrams(["abc", "def", "ghi"])
    assert sorted([group[0] for group in result]) == ["abc", "def", "ghi"]


def test_single_letter_groups(solution):
    result = solution.groupAnagrams(["a", "b", "a"])
    assert [sorted(group) for group in result] == [["a", "a"], ["b"]]
