레이캐스팅 정리

1. 기본 원리
	- 2차원 정사각형 그리드로 된 맵이 있다.
	- 맵의 한 칸은 0 또는 양수를 갖는다.
	- 화면의 모든 x값(수직선)에 대해 카메라(플레이어) 위치에서부터 시작하는 광선을 쏜다.
	- 광선의 방향은 카메라가 바라보는 방향이며 화면의 x 좌표에 의존한다.
	- 광선은 2D 맵 위에서 벽에 부딪히면 적중지점으로부터 카메라까지의 거리를 잰다.
	- 거리에 따라 벽의 높이가 결정된다.

2. 광선과 벽
	- 광선이 처음으로 부딪히는 벽을 찾으려면 광선을 카메라 위치에서부터 출발시켜 광선이 벽에 포함되는지 반복적으로 검사해야한다.
	- 벽에 포함된다면 loop를 멈추고 거리를 측정해서 알맞는 높이로 벽을 표현한다.
	- 광선의 경로 상에 있는 한정된 지점만 검사한다.
	- 레이캐스터는 광선의 위치에 일정한 값을 더해주며 반복하는 방식으로 벽에 부딪혔는지 검사한다.
	- 광선이 벽에 닿았는지는 알기 위해 DDA 알고리즘 혹은 브레젠험 알고리즘이 사용된다.

3. 벡터
	- 카메라의 위치는 항상 벡터(x, y 좌표)이다.
	- 방향은 방향벡터의 x, y 좌표로 결정된다.
	- 벡터를 이용하는 방법은 방향 벡터와 카메라 평면도가 필요함

4. 카메라 평면
	- 카메라를 뇌, 카메라 평면을 눈이라 생각하면 된다.
	- 카메라와 카메라 평면은 동일하게 움직인다.
	- 카메라 -> 카메라 평면 -> 광선 -> 랜더링 대상 의 순서를 가진다고 생각하면 된다.
	- 카메라와 카메라 평면 사이는 방향 벡터가 위치하며 카메라 평면은 방향 벡터에 항상 수직이다.
	- 수직이 아니라면 랜더링 대상이 왜곡되게 보인다.
	- 필요한 벡터
		- pos 벡터 = 카메라:플레이어 위치
		- dir 벡터 = 방향 벡터
		- plane 벡터 = 카메라 평면 벡터, 방향 벡터의 끝점부터 오른쪽 카메라 평면의 끝점 까지 거리
		- 방향 벡터 끝점 = pos + dir (벡터)
		- 오른쪽 카메라 평면의 끝점 = pos + dir + plane (벡터)
		- 왼쪽 카메라 평면의 끝점 = pos + dir - plane (벡터)

5. 광선의 방향
	- rayDirX, rayDirY
	- 방향 벡터 + 카메라 평면 * 배수
	- 카메라 평면을 직선이라 생각했을 때 카메라로부터 시작해서 직선의 어느 지점에 닿는지

6. FOV (Field Of View)
	- 방향 벡터로 서로 연결된 카메라와 카메라 평면이 있다. 카메라와 카메라 평면 양 끝점을 직선으로 연결하여 두 개의 삼각형을 만들었을 때 카메라 쪽의 각도를 더한 값이 FOV이다.
	- 탄젠트는 인자로 빗변과 밑변 사이의 각도가 들어가며 높이 / 밑변이 된다.
	- 아크 탄젠트는 인자로 탄젠트가 들어올 때 탄젠트의 인자인 각도를 꺼낼 수 있다.
	- tan(theta) = 높이 / 밑변 -> atan(tan(theta)) = atan(높이 / 밑변)
	- 이를 방향 벡터 dir (밑변), 방향 벡터부터 카메라 평면 끝까지의 길이 plane (높이), 빗변과 밑변 사이의 각도 (half FOV)에 적용하면
		- tan(half FOV) = plane / dir
		- atan(tan(half FOV)) = atan(plane / dir)
		- half FOV = atan(plane / dir) 이 된다
		- FOV의 전체값은 2 * half FOV 이므로 정리하면
		- FOV = 2 * atan(plane / dir) 이 된다.
	- FOV 값을 늘리면 방향 벡터 값은 늘어나고 카메라 평면 길이는 줄어든다
		- 방향 벡터 값이 늘어남 = 카메라 ~ 카메라 평면 간의 거리가 늘어남 = 렌더링 값이 작아진다 라고 생각 할 수 있다.
		- 하지만 방향 벡터 길이가 늘어나고 카메라 평면 길이가 줄어들기 때문에 화면에 표현 가능한게 적어지므로 확대 효과를 얻는다.
		- 3인칭 게임에서 마우스 휠을 돌려 줌인 효과를 줬을 때 화면에 표시되는 주변 화물이 적어지지만 캐릭터는 크게 보인다는 예시를 생각하면 좋음.
	- FOV 값을 줄이면 방향 벡터 값은 줄어들고 카메라 평면 길이는 늘어난다
		- 위 사례와는 반대로 화면에 표현 가능한게 늘어나므로 화면에 표시되는 주변 사물, 배경이 늘어나고 캐릭터는 작아지므로 축소 효과라고 생각하면 된다.

7. 실제 코드에서 구성
	- 예제 코드 04_floor_ceiling.c 를 참고
	- 해당 코드에는 초기값으로 방향 벡터(-1,0), 카메라 평면(0,0.66), 플레이어(22,12) 가 주어지는데 이를 좌표에 찍어보면 플레이어->방향벡터->카메라평면 순으로 찍혀있지 않은 것을 확인 할 수 있다.
	- 또한 계산결과(Cub3d.pdf 6페이지 참고) theta = 2 * atan(0.66 / 1.0) = 66.8 degree 값이 나온다.
	-  

8. 방향 회전
	- 카메라가 방향을 돌리면 시야도 따라서 회전해야한다.
	- 방향 벡터와 카메라 평면 벡터 모두 회전해야한다.
	- 회전 행렬을 곱하면 된다.
	- 증명 과정은 유튜브 (https://www.youtube.com/watch?v=OYuoPTRVzxY) 참고
	- x' = cos(theta)x - sin(theta)y
	- y' = sin(theta)x + cos(theta)y

9. 카메라
	- 방향에 직각이 아닌 카메라 평면을 사용하면 왜곡된 결과를 보게 된다.
		- 방향 벡터와 카메라 평면은 직각이어야 한다는 말임.

10. 메인 함수의 변수 선언
	- posX, posY 는 카메라(플레이어)의 초기 위치 벡터 posX = 22, posY = 12
	- dirX, dirY 는 카메라(플레이어)의 초기 방향 벡터 dirX = -1, dirY = 0
	- planeX, planeY 는 카메라 평면 planeX = 0, planeY = 0.66
		- 방향 벡터와 수직이기만 하면 카메라 평면의 길이는 다양할 수 있음
	- 이 떄의 카메라 평면의 길이 : 방향 벡터의 길이 의 비율로 FOV가 결정된다.
		- 이전에 유도한 식 : FOV = 2 * atan(0.66 / 1.0) -> 이해가 안 되는 지점, planeY / abs(dirX) 를 해준 이유?
	- time, oldTime 은 현재, 이전 프레임의 시간 저장
		- time과 oldTime의 시간차는 특정 키를 눌렀을 때 (프레임 계산하는데 얼마나 걸리건 일정한 속도로 움직이기 위해) 이동거리를 결정하고 FPS를 측정하는데 사용

11. 해상도 지정
	- 높은 해상도는 아무리 광선 추적 알고리즘이 빨라도 cpu에서 gpu로 전체화면을 불러오는게 오래 걸려서 렌더링이 느려짐

12. 화면 생성후 게임 루프 시작
	- while(!done) {}
	- 반복문, 전체 프레임을 그려내고 입력을 읽는 역할

13. 레이캐스팅 시작
	- for문

13. 광선의 시작점
	- 카메라(플레이어)의 위치.
	- posX, posY

14. 레이캐스팅 반복문에 필요한 변수 선언, 값 계산

15. 빈 공간 처리
	- 맵의 빈 공간이 스페이스가 아니라 탭이라면?
	- 1개의 탭 = 4개의 빈 칸 이지만 맵핑시엔 1 개의 탭 당 1 개의 빈 칸을 생성하지만 나머지 3칸 만큼은 가장 나중에 출력해서 맵이 이상하게 출력됨
	- 파싱때 예외를 두거나 맵핑시에 다른 처리 방법을 고민중

16. 이미지 관련 함수 정리
	- mlx_new_image
		- 이미지 생성
	- mlx_xpm_file_to_image
		- xpm 파일을 이미지로 생성, 성공시 이미지의 포인터 반환
		- 함수인자 width, height은 이미지의 width, height 값을 저장하기 위함
	- mlx_get_data_addr
		- 이미지의 정보를 가져옴
		- 프로토타입의 반환값은 char pointer
		- 해당 과제에서 int pointer로 형변환 하는 이유(추정)
			- 1. 텍스쳐(int **)에 미리 이미지를 저장하여 사용하는 경우 각각의 텍스쳐에 이미지를 복사하게 되는데 이때 형식을 맞춰주기 위함임.
			- 2. int 값인 bpp, size_line을 이용하여 메모리 주소 이동을 하는 경우 int pointer로 형변환 시켜줘야 하는 듯 (참고로 char pointer로 사용하는 경우 각각의 bpp, size_line에 접근해도 값이 0만 나왔음. 따라서 이게 형변환하는 이유로 추정됨)
			- 3. RGBA = 8 * 4 = 32비트, 32비트 정수(여러 바이트)를 한 번에(단일 엔티티로) 처리하기 위해서 char pointer를 int pointer로 형변환 시키는 것 (chatGPT 답변, 제일 그럴듯함) -> 24비트 RGB, 16비트 RGBA는 UB가 발생 할 수 있으므로 금지임
		- 함수인자
			- bpp(bit_per_pixel) : 픽셀에 색상을 나타내기 위해 필요한 비트수
			- size_line : 메모리 상에서 image의 한 행을 표현하는데 사용된 바이트 값
			- endian : image 상의 픽셀 색상 값이 리틀 엔디안(0)인지 빅 엔디안(1)인지
		- 목적
			- 메모리 상에 존재하는 image의 bpp, size_line 을 이용해 image를 조작하기 쉽게 해줌.
			- 예를 들어 bpp = 8 인 경우 mlx_get_data_addr 의 반환 값에서 8비트 만큼이 image의 첫 행의 첫 픽셀 색상을 나타냄. 그 다음 8비트는 image의 첫 행의 두 번째 픽셀 색상을 나타내는 값이 됨. image의 주소 값에 size_line 만큼 더하게 되면 image 의 두 번째 행의 시작 지점이 됨.
			- 요약하자면 image의 어떤 pixel에도 접근 할 수 있게 해줌.
		- 주의
			- 행으로 접근하기 때문에 2차원이라 생각할 수 있는데 1차원이기 때문에 접근에 주의해야함
			- texture[i + (img.img_row * j)] = img.img_data[i + (img.img_row * j)];
			- 위 코드처럼 이미지 전체를 복사하는 경우 1행을 탐색하고 그 다음 행으로 이동하는 경우 이미지의 길이만큼 더 해줘야 함
		- 메모리
			- Index:   0                1                2                3               ...          64*64 - 1
			- Memory:  [RGBA(255, 0, 0, 255)][RGBA(0, 255, 0, 255)][RGBA(0, 0, 255, 255)][RGBA(255, 255, 255, 255)] ... [Next pixels]
			- 1차원 배열이지만 2차원처럼 생각할 때, 다음 색상까지 거리 = size_l = 이미지의 크기 (TEX_WIDTH, TEXT_HEIGHT, img_width, img_height. 단, 전부 동일할 때) 과 동일
			- 전체를 순회할 때는 이중 반복문으로 texture[TEX_WIDTH * j + i] 로 체크하거나 복사하면 됨
	- mlx_destroy_image
		- Screen Connection 상에서 유지 중인 image를 지울 수 있음
