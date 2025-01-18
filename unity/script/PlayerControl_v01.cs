using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControl : MonoBehaviour
{
    public Transform viewPoint; // 玩家視角的位置（例如攝像機）
    public float mouseSensitivity = 1f; // 滑鼠靈敏度
    private float verticalRotation = 0f; // 垂直旋轉的累積值，用於限制上下視角
    private Vector2 mouseInput; // 滑鼠輸入的水平和垂直值

    // Start is called before the first frame update
    void Start()
    {
        // 鎖定滑鼠指針，並使其不可見
        Cursor.lockState = CursorLockMode.Locked;
        Cursor.visible = false;
    }

    // Update is called once per frame
    void Update()
    {
        // 獲取滑鼠的輸入
        mouseInput = new Vector2(Input.GetAxisRaw("Mouse X"), Input.GetAxisRaw("Mouse Y")) * mouseSensitivity;

        // 水平旋轉：更新角色的 Y 軸旋轉
        transform.rotation = Quaternion.Euler(transform.rotation.eulerAngles.x, transform.rotation.eulerAngles.y + mouseInput.x, transform.rotation.eulerAngles.z);

        // 垂直旋轉：更新攝像機的 X 軸旋轉，並限制角度範圍
        verticalRotation -= mouseInput.y;
        verticalRotation = Mathf.Clamp(verticalRotation, -60f, 60f); // 限制視角範圍為 -60 到 60 度
        viewPoint.localRotation = Quaternion.Euler(verticalRotation, 0f, 0f);
    }
}
