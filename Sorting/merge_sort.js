const merge = (A, start, middle, length) => {
    let left = [];
    let right = [];
    for (let index = start; index < middle; index++) {
        left.push(A[index]);
    }

    for (let index = middle; index < length; index++) {
        right.push(A[index]);
    }

    let l = 0;
    let r = 0;
    let k = 0;
    let result = [];

    while (l < left.length && r < right.length) {

        if (left[l] > right[r]) {
            result.push(right[r]);
            r++;
        }
        else {
            result.push(left[l]);
            l++;
        }
        k++;
    }

    while (l < left.length) {
        result.push(left[l]);
        l++;
    }

    while (r < right.length) {
        result.push(right[r]);
        r++;
    }

    console.log(result);
}

// merge([1, 3, 5, 2, 4, 6], 0, 3, 6);

const merge_sort = (A, l, r) => {

    if (l < r) {
        let m = l + (r - l) / 2;

        merge_sort(A, l, m);
        merge_sort(A, m + 1, r);
        merge(A, l, m, r);

    }

}

merge_sort([5, 4, 3, 2, 1]);
