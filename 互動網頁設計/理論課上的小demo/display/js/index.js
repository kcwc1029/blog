// TODO: 導入：dataProcesser.js
import { someData, someFn } from "./coreLogic.js";

const newData = { ...someData, extraKey: "extraValue" };
console.log(someFn(newData.key));
