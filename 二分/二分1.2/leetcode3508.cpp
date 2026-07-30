#include<bits/stdc++.h>
using namespace std;

class Router {
public:
    int memLimit = 0;
    int length = 0;
    set<tuple<int, int, int>> isExist;
    unordered_map<int, deque<int>> sameDestQue;
    deque<tuple<int, int, int>> que;

    Router(int memoryLimit) { memLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> packet =
            make_tuple(source, destination, timestamp);
        if (isExist.count(packet)) {
            return false;
        }
        if (length == memLimit) {
            forwardPacket();
        }
        length++;
        que.push_back(packet);
        sameDestQue[destination].push_back(timestamp);
        isExist.insert(packet);
        return true;
    }

    vector<int> forwardPacket() {
        vector<int> data;
        if (!que.empty()) {
            tuple<int, int, int> packet = que.front();
            que.pop_front();
            data = vector<int>{get<0>(packet), get<1>(packet), get<2>(packet)};
            isExist.erase(packet);
            sameDestQue[data[1]].pop_front();
            length--;    
        }
        return data;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto pos1 = lower_bound(sameDestQue[destination].begin(),
                                sameDestQue[destination].end(), startTime);
        auto pos2 = upper_bound(sameDestQue[destination].begin(),
                                sameDestQue[destination].end(), endTime);
        return pos2 - pos1;
    }
};

/*
    // 1) tuple 是什么？
    // =========================
    // tuple = “固定大小的打包盒”，里面装多个值，彼此类型可以不同（异构）。
    // 访问元素用 std::get<索引>(t)，索引从 0 开始。
    {
        tuple<int, string, double> box; // 一个“盒子”，里面是 (int, string, double)
        box = make_tuple(7, "apple", 3.14); // 也可以用 make_tuple 给它赋值

        cout << "tuple 示例：\n";
        cout << "  第0个元素(索引0)： " << get<0>(box) << "\n";
        cout << "  第1个元素(索引1)： " << get<1>(box) << "\n";
        cout << "  第2个元素(索引2)： " << get<2>(box) << "\n\n";
    }

    // ==========================================
    // 2) make_tuple 是什么？（如何“打包”）
    // ==========================================
    // make_tuple 用来把多个值打包成一个 tuple。
    // 你不用手写 tuple<int,string,double> 这种类型，编译器会自动推导。
    {
        cout << "make_tuple 示例：\n";
        auto packet = make_tuple(1, 99, "hello"); 
        // packet 的类型会自动变成 tuple<int,int,string>

        cout << "  我们把 (1, 99, \"hello\") 打包成 tuple。\n";
        cout << "  get<0>: " << get<0>(packet) << "\n";
        cout << "  get<1>: " << get<1>(packet) << "\n";
        cout << "  get<2>: " << get<2>(packet) << "\n\n";
    }

    // =========================
    // 3) deque 是什么？
    // =========================
    // deque = 双端队列：两端都能高效“放”和“取”
    // 常见操作：
    //   push_front / pop_front ：在队头加/删
    //   push_back  / pop_back  ：在队尾加/删
    // 并且 deque 是普通容器，支持 begin()/end()，可以做遍历、也能用 lower_bound 等算法。
    {
        cout << "deque 示例（双端队列）：\n";
        deque<int> dq;

        // 类似“票据/卡片”，你既可以从左边取，也可以从右边放
        dq.push_back(10);  // 队尾放入
        dq.push_back(20);  // 队尾放入
        dq.push_front(5);  // 队头放入

        cout << "  当前队列元素（从队头到队尾）： ";
        for (int x : dq) cout << x << " ";
        cout << "\n";

        cout << "  front(队头)： " << dq.front() << "\n";
        cout << "  back(队尾)  ： " << dq.back()  << "\n";

        dq.pop_front(); // 从队头删
        dq.pop_back();  // 从队尾删

        cout << "  删除队头和队尾后，剩余元素个数：" << dq.size() << "\n\n";
    }

    // ==================================================
    // 4) 综合例子：deque<tuple<...>> 怎么用？
    // ==================================================
    // 通俗比喻：deque 里存“消息包（packet）”，每个 packet 用 tuple 表示三个字段：
    //   (from, to, time)
    // 然后：
    //   - push_back 把新消息放到队尾（模拟收到新包）
    //   - pop_front 取出最早的消息（FIFO 转发）
    // 同时：tuple 让每个消息拥有“结构化字段”，用 get<0/1/2> 取值。
    {
        cout << "综合示例：deque<tuple<int,int,int>>（消息包队列）\n";
        deque<tuple<int, int, int>> q; 
        // q 里每个元素是 (source, destination, timestamp)

        q.push_back(make_tuple(1, 3, 100)); // from=1, to=3, time=100
        q.push_back(make_tuple(2, 3, 101));
        q.push_back(make_tuple(7, 4, 105));

        cout << "  取出（FIFO）：\n";
        while (!q.empty()) {
            auto packet = q.front(); // 取队头，但不弹
            q.pop_front();           // 弹出队头

            int from = get<0>(packet);
            int to   = get<1>(packet);
            int time = get<2>(packet);

            cout << "    packet: from=" << from
                 << ", to=" << to
                 << ", time=" << time << "\n";
        }
        cout << "\n";
    }

*/