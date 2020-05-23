import "strings"

func wordPattern(pattern string, str string) bool {
	words := strings.Fields(str);

	wordMap := make(map[string]byte)
	patternMap := make(map[byte]string)
	
	if len(pattern) != len(words) {return false;}

	for idx, word := range words {
		ch := pattern[idx]
		_, wordAppeared := wordMap[word]
		_, patternAppeared := patternMap[ch]

		if !wordAppeared && !patternAppeared {
			wordMap[word] = ch;
			patternMap[ch] = word;
			continue;
		}
		
		if !wordAppeared || !patternAppeared {
			return false
		}

		if wordMap[word] != ch || patternMap[ch] != word { return false; }
	}

	return true;
}