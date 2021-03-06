#
# ListTest: Tests for Reia's list type
# Copyright (C)2008 Tony Arcieri
# 
# Redistribution is permitted under the MIT license.  See LICENSE for details.
#

module ListTestHelper
  def some_list
    [1,3,5,7,9]
  end
end

module ListTest
  def run
    [
      size_test(), 
      nth_test(),
      first_test(),
      first_n_test(),
      last_test(),
      last_n_test(),
      min_test(),
      max_test(),
      replace_test(),
      complex_replace_test(),
      reverse_test(), 
      join_test(),
      append_test(),
      each_test(),
      map_test(),
      all_test(),
      any_test(),
      select_test(),
      partition_test(),
      flatten_test(),
      #parenless_sugar_test(), # FIXME this should work eventually...
      to_list_test(),
      to_tuple_test(), 
      to_dict_test(),
      to_string_test(),
      to_s_test(),
      inspect_test()
    ]
  end
  
  # knows its size
  def size_test
    TestHelper.expect(List, "knows its size") do
      list = [1,2,3,4,5]
      (5, list.size())
    end
  end
  
  # retrieves the nth element correctly
  def nth_test
    TestHelper.expect(List, "retrieves the nth element correctly") do    
      list = [1,2,3,4,5]
      (true, list[0] == 1 and list[1] == 2 and list[4] == 5 and list[-1] == 5 and list[-3] == 3 and list[-10] == nil)
    end
  end

  def first_test
    TestHelper.expect(List, "retrieves the first element") do
      (4, [4,7,9].first())
    end
  end

  def first_n_test
    TestHelper.expect(List, "retrieves the first N elements") do
      ([4,7], [4,7,9].first(2))
    end

    TestHelper.expect(List, "retreives whole list if N exceeds list size") do
      ([4,7,9], [4,7,9].first(1000))
    end
  end

  def last_test
    TestHelper.expect(List, "retreives the last element") do
      (9, [4,7,9].last())
    end
  end

  def last_n_test
    TestHelper.expect(List, "retreives the last N elements") do
      ([7,9], [4,7,9].last(2))
    end

    TestHelper.expect(List, "retreives whole list if N exceeds list size") do
      ([4,7,9], [4,7,9].last(1000))
    end
  end

  def min_test
    TestHelper.expect(List, "retreives smallest element in the list") do
      (3, [5,9,3,13,42,7].min())
    end
  end

  def max_test
    TestHelper.expect(List, "retreives largest element in the list") do
      (42, [5,9,3,13,42,7].max())
    end
  end
  
  # replaces elements in pattern matching expressions
  def replace_test
    TestHelper.expect(List, "replaces elements in pattern matching expressions ") do
      list = [1,2,3]
      list[1] = 42
      list[2] = 69
    
      ([1,42,69], list)
    end
  end
  
  # replaces elements in complex pattern matching expressions
  def complex_replace_test
    TestHelper.expect(List, "replaces elements in complex pattern matching expressions ") do
      list = [1,2,3,4]
      (list[1], [list[0], list[2]]) = (9, [8, 10])
    
      ([8,9,10,4], list)
    end
  end

  # reverses the order of a list
  def reverse_test
    TestHelper.expect(List, "reverses the order of a list") do
      ([3,2,1].to_s(), [1,2,3].reverse().to_s())
    end
  end

  # joins together into a string    
  def join_test
    TestHelper.expect(List, "joins into a string") do
      ("1,2,3", [1,2,3].join(','))
    end
  end

  # concatenates two lists together to form a third list
  def append_test
    TestHelper.expect(List, "is concatenated with another list") do
      ([1,2,3,4,5,6], [1,2,3].append([4,5,6]))
    end
  end
  
  # iterates each element
  def each_test
    TestHelper.expect(List, "iterates each element") do
      # FIXME: this doesn't actually test the block produces a side effect
      ([1,2,3], [1,2,3].each { |n| n })
    end
  end
  
  # maps to a block
  def map_test
    TestHelper.expect(List, "maps to a block") do
      ([40,41,42], [1,2,3].map { |n| n + 39 })
    end
  end

  def all_test
    TestHelper.expect(List, "can tell when all elements match a cond") do
      (true, [1,2,3].all? { |x| x < 4 })
    end

    TestHelper.expect(List, "can tell when not all elements match a cond") do
      (false, [1,2,3].all? { |x| x > 2 })
    end
  end

  def any_test
    TestHelper.expect(List, "can tell when an element matches a cond") do
      (true, [1,2,3].any? { |x| x == 2 })
    end

    TestHelper.expect(List, "can tell when no elements match a cond") do
      (false, [4,5,6].any? { |x| x == 2 })
    end
  end

  def select_test
    TestHelper.expect(List, "can select certain elements to form a new list") do
      ([2,4,6], [1,2,3,4,5,6].select { |x| x % 2 == 0 })
    end
  end

  def partition_test
    TestHelper.expect(List, "can be partitioned") do
      (([2,4,6],[1,3,5]), [1,2,3,4,5,6].partition { |x| x % 2 == 0 })
    end
  end

  # flattens from a deep list
  def flatten_test
    TestHelper.expect(List, "flattens from a deep list") do
      ([1,2,3,4,5,6], [1,[[2,3],4,5],6].flatten())
    end
  end
  
#  def parenless_sugar_test
#    TestHelper.expect(List, "members can be retrieved from function results without parens") do
#      (5, ListTestHelper.some_list[2])
#    end
#  end
  
  # converts to a list
  def to_list_test
    TestHelper.expect(List, "converts to a list") do
      ([1,2,3], [1,2,3].to_list())
    end
  end
    
  # converts to a tuple  
  def to_tuple_test
    TestHelper.expect(List, "converts to a tuple") do
      ((1,2,3), [1,2,3].to_tuple())
    end
  end
  
  # converts to a dict
  def to_dict_test
    TestHelper.expect(List, "converts to a dict") do
      ([(:foo, "bar"), (:bar, "bar")].to_dict(), {:foo => "bar", :bar => "bar"})
    end
  end
  
  # converts to a string
  def to_string_test
    TestHelper.expect(List, "converts to a string") do
      ("surprise", [115,117,114,112,114,105,115,101].to_string())
    end
  end
  
  # casts to a string
  def to_s_test
    TestHelper.expect(Binary, "casts to a string") do
      ("[115,117,114,112,114,105,115,101]", [115,117,114,112,114,105,115,101].to_s())
    end
  end
  
  # inspects properly
  def inspect_test
    TestHelper.expect(Binary, "inspects properly") do
      ("[115,117,114,112,114,105,115,101]", [115,117,114,112,114,105,115,101].inspect())
    end
  end
end
