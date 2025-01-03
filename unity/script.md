## script：通過滑鼠輸入來控制角色的旋轉和相機的視角移動

-   這個腳本是一個角色控制器，實現了基於滑鼠視角旋轉和鍵盤控制的移動功能。角色的移動方向根據主相機的朝向進行計算，適合用於第一人稱或第三人稱遊戲。

```
Player (掛在這邊)
├── cubd
└── View Point (掛在View Point)
    └── main cameraw Point)/
        └── main camera (掛在cameraTransform)
```

```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public Transform viewPoint; // 相機觀察點
    public Transform cameraTransform; // 主相機 (需在 Inspector 中拖入)
    public float mouseSensitivity = 2f; // 滑鼠靈敏度
    public float moveSpeed = 5f; // 移動速度
    public bool invertLook = false; // 是否反轉視角

    private float verticalRotStore; // 儲存垂直旋轉角度
    private Vector2 mouseInput; // 儲存滑鼠輸入
    private Vector3 moveDir; // 儲存移動方向
    private Vector3 movement; // 儲存最終移動量

    void Start()
    {
        // 鎖定滑鼠指標到螢幕中心並隱藏
        Cursor.lockState = CursorLockMode.Locked;
        Cursor.visible = false;
    }

    void Update()
    {
        // 1. **滑鼠輸入：控制視角旋轉**
        mouseInput = new Vector2(Input.GetAxis("Mouse X"), Input.GetAxis("Mouse Y")) * mouseSensitivity;

        // 水平旋轉角色
        transform.rotation = Quaternion.Euler(transform.rotation.eulerAngles.x,
                                              transform.rotation.eulerAngles.y + mouseInput.x,
                                              transform.rotation.eulerAngles.z);

        // 垂直旋轉相機（限制視角範圍在 -60 到 60 度）
        verticalRotStore += invertLook ? mouseInput.y : -mouseInput.y;
        verticalRotStore = Mathf.Clamp(verticalRotStore, -60f, 60f); // 限制視角
        viewPoint.rotation = Quaternion.Euler(verticalRotStore, transform.rotation.eulerAngles.y, 0f);

        // 2. **鍵盤輸入：控制移動方向**
        float moveX = Input.GetAxis("Horizontal"); // 左右移動 (A/D 或 左/右鍵)
        float moveZ = Input.GetAxis("Vertical");   // 前後移動 (W/S 或 上/下鍵)

        // 根據相機方向計算移動方向
        Vector3 forward = cameraTransform.forward; // 相機的前方向
        Vector3 right = cameraTransform.right;     // 相機的右方向
        forward.y = 0; // 忽略 Y 軸，確保角色僅在水平面移動
        right.y = 0;
        forward.Normalize();
        right.Normalize();

        moveDir = (forward * moveZ + right * moveX).normalized;

        // 3. **計算最終移動量並應用到角色位置**
        movement = moveDir * moveSpeed * Time.deltaTime;
        transform.position += movement; // 更新角色位置
    }
}
```
