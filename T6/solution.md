# [problem:208021A]

## Sinh số nguyên tố

Số số nguyên tố nhỏ hơn hoặc bằng $N$ là $O(N / log(N))$, nên để sinh được 50k số nguyên tố, thì ta cần xét đến tầm 1 triệu (có thể kiểm chứng cận trên chính xác bằng code). Dễ dàng sinh được các số nguyên tố cần thiết bằng sàng.

## Xóa tối ưu

Thay vì nghĩ là ta cần xóa $K$ chữ số, hãy nghĩ là ta cần giữ lại $N-K$ chữ số.

Giờ giả sử ta có số $91435$ và ta cần giữ lại 2 chữ số, rõ ràng ta sẽ giữ lại số $95$. Tại sao? Rõ ràng số lớn nhất nếu chữ số đầu tiên lớn nhất, nên ta giữ lại 9. Ta luôn giữ lại chữ số to nhất có thể, sao cho nếu giữ lại chữ số đó thì ta vẫn đủ chữ số. Ví dụ khác: $11199$ và cần giữ lại 3 chữ số --> không thể để chữ số đầu tiên là 9, vì như thế thì sẽ không có đủ 3 chữ số.

Do đó, cách làm là: đi từ trái sang phải, chọn chữ số lớn nhất để giữ lại sao cho vẫn còn đủ $X$ chữ số cần giữ lại. Ví dụ:

- Chữ số đầu tiên giữ lại là $max(A1..A(N-X+1)$. Đặt chỉ số của nó là $i1$.
- Chữ số thứ 2 giữ lại là $max(A(i1)..A(N-X+2)$.
...


# [problem:208021B]

Hướng đi thông thường là quy hoạch động theo kiểu $f(i, j, x)$, là nếu chỉ xét người từ $i$ đến $j$, thì thằng $x$ có vô địch được không. Tuy nhiên làm kiểu này độ phức tạp rất lớn và bộ nhớ cũng lớn.

Ta nhận thấy chiều $x$ không quan trọng, nói cách khác, ta sửa lại hàm $f(i, j)$ là có tồn tại cách chơi, để khi chơi hết đoạn $i$ đến $j$, thì còn lại cả $i$ và $j$.

Từ đó thu được công thức quy hoạch động $N^3$ rất đơn giản:

$f(i, j) = true$ nếu tồn tại $k$ mà $f(i, k) = f(k, j) = 1$ và $A(i,k) = 1 || A(j,k) = 1$.


# [problem:208021C]

Bài dạng này có rất nhiều cách đi. Điểm quan trọng khi làm những bài như này là tìm cách nào đơn giản, logic nhất để code.

Cách tiếp cận đơn giản nhất là chia nhỏ hình cần tìm ra theo cấu trúc của nó và quy hoạch động theo từng phần:

- $top(i, l, r)$ là khối bên trên lớn nhất, nếu cạnh dưới ở hàng i, và nằm trong khoảng $[l, r]$.
- $bot(i, l, r)$ là khối bên dưới lớn nhất, nếu cạnh trên ở hàng i, và nằm trong khoảng $[l, r]$.
- $mid(i, l, r)$ là khối trên + giữa lớn nhất, nếu cạnh dưới ở hàng i, và cạnh đáy đúng bằng $[l, r]$.

Việc tính 3 mảng này đơn giản. Sau khi có $mid$ và $bot$, gộp 2 phần này với nhau thì thu được hình kết quả.
