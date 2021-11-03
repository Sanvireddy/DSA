vector<int> dNums(vector<int> &A, int B)
// {
//     vector<int> v;
//     if (A.size() == 0)
//         return v;
//     if (A.size() == 1)
//         return {1};
//     unordered_map<int, int> m;
//     int j = 0, i = 1;
//     while (j < B)
//     {
//         m[A[j]]++;
//         j++;
//     }
//     v.push_back(m.size());
//     while (i <= (A.size() - B))
//     {
//         m[A[i - 1]]--;
//         m[A[i + B - 1]]++;
//         if (m[A[i - 1]] == 0)
//         {
//             m.erase(A[i - 1]);
//         }
//         v.push_back(m.size());
//         i += 1;
//     }
//     return v;
// }