#include <stdio.h>
#define TAKEN 1
#define NOT_TAKEN 0
#define STRONGLY_TAKEN 3
#define STRONGLY_NOT_TAKEN 0

// Structure representing a branch predictor
typedef struct {
    int state; // State of the predictor (2-bit saturating counter)
} BranchPredictor;

// Initialize the branch predictor
void init_predictor(BranchPredictor *predictor) {
    predictor->state = STRONGLY_NOT_TAKEN;
}

// Predict the outcome of a branch instruction
int predict(BranchPredictor *predictor) {
    if (predictor->state >= 2) {
        return TAKEN;
    } else {
        return NOT_TAKEN;
    }
}

// Update the branch predictor based on the actual outcome
void update_predictor(BranchPredictor *predictor, int actual_outcome) {
    if (actual_outcome == TAKEN) {
        if (predictor->state < STRONGLY_TAKEN) {
            predictor->state++;
        }
    } else {
        if (predictor->state > STRONGLY_NOT_TAKEN) {
            predictor->state--;
        }
    }
}

int main() {
    BranchPredictor predictor;
    init_predictor(&predictor);

    // Simulate branch prediction for a sequence of branch instructions
    int branch_outcomes[] = {TAKEN, TAKEN, NOT_TAKEN, TAKEN, NOT_TAKEN};
    int num_branches = sizeof(branch_outcomes) / sizeof(branch_outcomes[0]);

    printf("Branch prediction results:\n");
    for (int i = 0; i < num_branches; i++) {
        int prediction = predict(&predictor);
        printf("Branch %d: Prediction = %s\n", i + 1, prediction == TAKEN ? "Taken" : "Not Taken");
        update_predictor(&predictor, branch_outcomes[i]);
    }

    return 0;
}
