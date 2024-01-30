
class compare
{
public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge K sorted linked list.
    priority_queue<Node*, vector<Node*>, compare> pq;

    Node* mergeKLists(Node* arr[], int K)
    {
        for (int i = 0; i < K; i++)
        {
            if (arr[i] != nullptr)
            {
                pq.push(arr[i]);
            }
        }

        Node* head = nullptr;
        Node* tail = nullptr;

        while (!pq.empty())
        {
            Node* top = pq.top();
            pq.pop();

            if (top->next != nullptr)
            {
                pq.push(top->next);
            }

            if (head == nullptr)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};
