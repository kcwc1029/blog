const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.set(0, 5, 20); // Camera 身為鏡頭,有位置屬性,設定在Z軸即可

// 實例化選染器
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight); // 渲染器負責投影場景在螢幕上,會需要寬高
document.body.appendChild(renderer.domElement); // 渲染器會產生canvas物件,我們在html的body放置它

// 建立形狀
const geometry = new THREE.BoxGeometry(1, 1, 1); // 建立一個形狀，長寬高為1的正方體
const material = new THREE.MeshNormalMaterial(); // 使用帶顏色的材質
const cube01 = new THREE.Mesh(geometry, material);
scene.add(cube01);

// TODO: 使用 Matrix4 對 cube01 進行 X 軸旋轉
const rotateMatrix = new THREE.Matrix4().makeRotationX(Math.PI / 4); // X 軸旋轉
cube01.applyMatrix4(rotateMatrix);

// TODO: 使用 Matrix4 對 cube02 進行縮放
const cube02 = new THREE.Mesh(geometry, material);
scene.add(cube02);
const scaleMatrix = new THREE.Matrix4().makeScale(2, 1, 1); // X 軸縮放 2 倍
cube02.applyMatrix4(scaleMatrix);

// TODO: 使用 Matrix4 對 cube03 進行位移
const cube03 = new THREE.Mesh(geometry, material);
scene.add(cube03);
const translationMatrix = new THREE.Matrix4().makeTranslation(5, 0, 0);
cube03.applyMatrix4(translationMatrix);

function animate() {
    requestAnimationFrame(animate); // 它每一幀執行 animate()
    renderer.render(scene, camera); // 每一幀,場景物件都會被鏡頭捕捉
}
animate();
