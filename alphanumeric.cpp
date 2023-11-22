#include <iostream>
#include <pthread.h>
#include <sstream>
#include <atomic>
#include <sstream>

std::string input;
int currentThread = 1;
bool printAlpha = true;
std::atomic<bool> done(false);


auto numeric(const std::string& word) {
    return !word.empty() && isdigit(word[0]);
}

auto alpha(const std::string& word) {
    return !word.empty() && isalpha(word[0]);
}
void* checker(void* s1) {
    int threadId = *(int*)s1;
    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        while ((threadId == 1 && !printAlpha) || (threadId == 2 && printAlpha)) {
        }
        if ((threadId == 1 && alpha(word)) || (threadId == 2 && numeric(word))) {
            std::cout << (threadId == 1 ? "alpha: " : "numeric: ") << word << std::endl;
        }
        printAlpha = !printAlpha;
        currentThread = (threadId == 1) ? 2 : 1;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t p1, p2;

    int alphaThreadId = 1;
    int numericThreadId = 2;

    std::cout << "Enter String: ";
    std::getline(std::cin, input);
    std::cout << "\n----------------------------------\n";

    pthread_create(&p1, NULL, checker, &alphaThreadId);
    pthread_create(&p2, NULL, checker, &numericThreadId);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);


    std::cout << "----------------------------------\n";
    return 0;
}
