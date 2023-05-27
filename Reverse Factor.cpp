#include <iostream>
#include <vector>

std::vector<int> reverse_factor(std::vector<int> lst) {
    int start = 0;
    int end = lst.size() - 1;
    while (start < end) {
        int temp = lst[start];
        lst[start] = lst[end];
        lst[end] = temp;
        start++;
        end--;
    }
    return lst;
}

int main() {
    std::vector<int> input_list;
    input_list.push_back(1);
    input_list.push_back(2);
    input_list.push_back(3);
    input_list.push_back(4);
    input_list.push_back(5);

    std::vector<int> reversed_list = reverse_factor(input_list);

    // In danh sách dã d?o ngu?c
    for (int i = 0; i < reversed_list.size(); i++) {
        std::cout << reversed_list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

