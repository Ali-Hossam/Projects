#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> keys, left_idx_vector, right_idx_vector;
std::vector<int> nodes_vector;
bool is_correct = true;
bool is_right_tree = true;


void bst_check(int i, std::vector<int>& nodes_vector, bool is_right_tree)
{
    if(is_correct)
    {
        int key = keys[i];
        int left_idx = left_idx_vector[i];
        int right_idx = right_idx_vector[i];

        if(right_idx != -1)
        {
            is_right_tree = true;
            bst_check(right_idx, nodes_vector, is_right_tree);

        }
        if(nodes_vector.size())
        {
            int last_key = nodes_vector[nodes_vector.size() -  1];
            if(is_right_tree)
            {
                if(key <= last_key)
                {
                    nodes_vector.push_back(key);
                }else
                {
                    is_correct = false;
                }
            }else
            {
                // std::cout << "last key" << last_key << key << std::endl;

                if(key < last_key)
                {
                    nodes_vector.push_back(key);
                }else
                {
                    is_correct = false;
                }
            }
        }else
        {
            nodes_vector.push_back(key);
        }
        
        if(left_idx != -1)
        {
            is_right_tree = false;
            bst_check(left_idx, nodes_vector, is_right_tree);
        }
    }
}


int main()
{
    int nodes;
    std::cin >> nodes;

    if(!nodes)
    {
        std::cout << "CORRECT";
        return 0;
    }

    for(int i = 0; i < nodes; i++)
    {
        int key, left, right;
        std::cin >> key >> left >> right;
        keys.push_back(key);
        left_idx_vector.push_back(left);
        right_idx_vector.push_back(right);
    }

    bst_check(0, nodes_vector, is_right_tree);


    if(is_correct){std::cout << "CORRECT";}else{std::cout << "INCORRECT";}
    // std::cout << std::endl;
    // for(int i : nodes_vector){std::cout << i << std::endl;}
}
