Lint_526_Load_Balancer.cpp
class LoadBalancer {
public:
    LoadBalancer() {
        srand(time(NULL)); // random seed
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        int idx = server.size();
        dict[server_id] = idx;
        server.push_back(server_id);
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // use the last element to replace the server_id
        int index = dict[server_id];
        dict[server.back()] = index;
        server[index] = server.back();
        server.pop_back();
        dict.erase(dict.find(server_id));
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        int index = rand()%server.size();
        return server[index];
    }
private:
    unordered_map<int,int> dict; // server_id --> index in vector
    vector<int> server; // for random
};
