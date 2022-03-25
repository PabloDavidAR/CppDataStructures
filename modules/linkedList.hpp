namespace linkedList {

    template <typename T>
    struct node{
        T data;
        node * next;
    };

    template <typename T>
    class linkedList{
        public:
            linkedList();

            void push(T);
            void push(node<T> *);

            node<T> * pop();
            node<T> * popByValue(T);

            int checkLength();

        private:
            node<T> * head;
            int length;
    };
}