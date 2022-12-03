
    //二個目以降
    for (int i = 0; i < n-m; i++) {
        int ans = anss[i] - cums[i+m] + cums[i] + (m * a[i+m]);
        cout << "cums[" << i+m << "] : " << cums[i+m] << endl;
        cout << ans << endl;
        anss.push_back(ans);
    }

    print(cums);
    print(anss);