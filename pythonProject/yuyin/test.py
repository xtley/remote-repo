
def SpectralSub(signal ,wlen ,inc ,NIS ,a ,b):
	wnd = np.hamming(wlen) # 使用汉明窗口进行加窗
	y = enframe(signal ,wnd ,inc) # 对信号进行分帧
	fn ,flen = y.shape # 获取分帧后的行数和列数
	y_a = np.abs(np.fft.fft(y ,axis=1)) # 计算分帧信号的幅度谱
	y_a2 = np.power(y_a ,2) # 计算幅度谱的平方
	y_angle = np.angle(np.fft.fft(y ,axis=1)) # 计算分帧信号的相位谱
	Nt = np.mean(y_a2[:NIS] ,axis=0) # 计算噪声估计值
	y_a2 = np.where(y_a 2> = a *Nt ,y_a 2 - a *Nt , b *Nt) # 根据设定的阈值参数进行频谱减法处理
	y_a2sqrt = np.sqrt(y_a2) # 对处理后的幅度谱进行开方操作
	sig = OverlapAdd2(y_a2sqrt ,y_angle ,wlen ,inc) # 执行重叠相加处理
	return sig # 返回处理后的信号
