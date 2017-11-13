class LRUCache {
private:
	int capacity;
	list<int> cache;
	unordered_map<int, pair<int, list<int>::iterator>> hm;

	void touch(int key) {
		int value = hm[key].first;
		cache.erase(hm[key].second);
		cache.push_front(key);
		hm[key].second = cache.begin();
	}
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (hm.find(key) == hm.end()) {
			return -1;
		}

		touch(key);
		return hm[key].first;
	}

	void put(int key, int value) {
		// check capacity
		if (hm.find(key) == hm.end()) {
			if (cache.size() == capacity) {
				// remove one item from cache
				auto it = cache.rbegin();
				hm.erase(*it);
				cache.pop_back();
			}

			cache.push_front(key);
			hm[key] = make_pair(value, cache.begin());
		} else {
			// update cache
			touch(key);
			hm[key].first = value;
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
