
void showHiddenWord(char word[]);

int main() {
    const int max = 6;
    char secretWord[] = "entuerto";
    char word[] = "_________";
    int fails = 0;

    do {
        showHiddenWord(word); // ___e__e__
        char letter = getLetter();
        /*bool isLetterInWord = checkLetter(word, letter);
        if (isLetterInWord) {
            changeHiddenWord(word, letter);
        } else {
            // Intento fallido
            fails++;
        }*/
        if (!checkAndChange(word, letter)) {
            fails++;
        }
    } while(!win() && fails < max);
    // win puede ser areEquals(word, secretWord)
    // win puede ser unresolvedLetters(word) == 0
}
