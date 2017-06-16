package string.detect_capital

class DetectCapital {
    def detectCapitalUse(word: String) : Boolean = {
        if (word.isEmpty())
            return true
        if (isCapital(word.charAt(0))) {
            return word.forall(isCapital) ||
                word.substring(1).forall(x => !isCapital(x))
        }
        return word.forall(x => !isCapital(x))
    }
    private def isCapital(c: Char) : Boolean =  {
        return c >= 'A' && c <= 'Z'
    }
}