package string.detect_capital

import org.scalatest.FunSuite

class DetectCapitalTest extends FunSuite {
  var solver = new DetectCapital

  test("All letters in this word are capitals, like \"USA\".") {
    assert(solver.detectCapitalUse("USA"))
  }

  test("All letters in this word are not capitals, like \"leetcode\".") {
    assert(solver.detectCapitalUse("leetcode"))
  }

  test("Only the first letter in this word is capital if it has more than one letter, like \"Google\".") {
    assert(solver.detectCapitalUse("Google"))
  }

  test("Empty word is valid.") {
    assert(solver.detectCapitalUse(""))
  }

  test("One character words.") {
    assert(solver.detectCapitalUse("A"))
    assert(solver.detectCapitalUse("a"))
  }

  test("Invalid words.") {
    assert(! solver.detectCapitalUse("FlaG"))
    assert(! solver.detectCapitalUse("FlaG"))
  }

}