//
//  main.swift
//  Bianry_tree_inorder
//
//  Created by Nguyen on 14/6/26.
//

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}


func inorderTraversal(_ root: TreeNode?) -> [Int] {
    var result = [Int]()
    
    func inorder(_ node: TreeNode?) {
        guard let node = node else { return }
        inorder(node.left)
        result.append(node.val)
        inorder(node.right)
    }
    inorder(root)
    return result
}

let root = TreeNode(1)
root.right = TreeNode(2)
root.right?.left = TreeNode(3)

print(inorderTraversal(root))

