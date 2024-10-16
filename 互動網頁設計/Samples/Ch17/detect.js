var mobile_device = navigator.userAgent.match(/iPad|iPhone|android|htc|sony/i);
if (mobile_device === null) document.location.replace('pc.html');
else document.location.replace('mobile.html');