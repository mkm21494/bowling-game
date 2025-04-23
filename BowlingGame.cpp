#include <iostream>
#include <vector>

class BowlingGame {
private:
    std::vector<int> rolls;  // Stores the result of each roll

public:
    // Called for each roll in the game
    void roll(int pins) {
        rolls.push_back(pins);
    }

    // Calculate the total score according to bowling rules
    int score() {
        int totalScore = 0;
        int i = 0;  // Index for the rolls vector

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(i)) {
                // Strike: score + next two rolls
                totalScore += 10 + strikeBonus(i);
                i += 1; // Strike is a single roll
            } else if (isSpare(i)) {
                // Spare: score + next roll
                totalScore += 10 + spareBonus(i);
                i += 2;
            } else {
                // Normal frame
                totalScore += frameScore(i);
                i += 2;
            }
        }
        return totalScore;
    }

private:
    bool isStrike(int i) {
        return rolls[i] == 10;
    }

    bool isSpare(int i) {
        return rolls[i] + rolls[i + 1] == 10;
    }

    int strikeBonus(int i) {
        return rolls[i + 1] + rolls[i + 2];
    }

    int spareBonus(int i) {
        return rolls[i + 2];
    }

    int frameScore(int i) {
        return rolls[i] + rolls[i + 1];
    }
};

int main() {
    BowlingGame game;

    // Example rolls from the image: 5 4 | 1 5 | 10 | 9 0 | 10 | 10 | 9 1 | 10 | 10 | 2 6
    int exampleRolls[] = {5, 4, 1, 5, 10, 9, 0, 10, 10, 9, 1, 10, 10, 2, 6};

    for (int pins : exampleRolls) {
        game.roll(pins);
    }

    std::cout << "Final Score: " << game.score() << std::endl;

    return 0;
}

