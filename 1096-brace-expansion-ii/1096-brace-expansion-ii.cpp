class Solution {
public:
    int i = 0;
    string expr;

    set<string> parseUnion() {
        set<string> result = parseConcat();
        while (i < expr.size() && expr[i] == ',') {
            i++;
            set<string> next = parseConcat();
            result.insert(next.begin(), next.end());
        }
        return result;
    }

    set<string> parseConcat() {
        vector<set<string>> parts;
        while (i < expr.size() && expr[i] != ',' && expr[i] != '}') {
            if (expr[i] == '{') {
                i++;
                parts.push_back(parseUnion());
                i++; // skip '}'
            } else {
                int j = i;
                while (j < expr.size() && islower(expr[j])) j++;
                parts.push_back({expr.substr(i, j - i)});
                i = j;
            }
        }
        set<string> result = {""};
        for (auto& p : parts) {
            set<string> merged;
            for (auto& a : result)
                for (auto& b : p)
                    merged.insert(a + b);
            result = merged;
        }
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        expr = expression;
        i = 0;
        set<string> res = parseUnion();
        return vector<string>(res.begin(), res.end());
    }
};