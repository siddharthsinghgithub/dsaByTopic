class treeNode {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

let bTree = new treeNode(1);
bTree.left = new treeNode(2);
bTree.right = new treeNode(3);

bTree.left.left = new treeNode(4);
bTree.left.right = new treeNode(5);
bTree.right.left = new treeNode(6);
bTree.right.right = new treeNode(7);


let preOrderTraversal = (bTree) => {
    if (bTree == null)
        return;
    console.log(bTree.data);
    preOrderTraversal(bTree.left);
    preOrderTraversal(bTree.right);

}

// let preOrderTraversal
preOrderTraversal(bTree);
