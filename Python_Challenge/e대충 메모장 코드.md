```c#
public int moveSpeed;  // 보통 이동 속도
public int maxSpeed;  // 최대 이동 속도
public int stopPointX;  // 이동 중 퍼즐 구간에 왔을 때
public stopDistance;  // 퍼즐 구간 거리

private Rigidbody2D rigidbody;
private bool isSolved;  // 퍼즐을 품

start(){
    rigidbody = Getcomponent<RigidBody2D>();
    isSolved = false;
}
FixedUpdate(){
	rigidbody.Addforce(Vector2.right*moveSpeed, ForceMode2D.Impulse);
    
    if(rigidbody.velocity.x > maxSpeed)
        rigidbody.velocity.x = new Vector2(maxSpeed, rigidbody.velocity.y);
    if(stopPointX < transform.position.x < stopPoint + stopDistance && !isSolved)
        rigidbody.velocity = new Vector2(rigidbody.velocity.x * 0.5f, _rigidbody.velocity.y);
    if(transform.position.x > stopPoint + stopDistance)
        isSolved = false;        
}
```

```
private SpriteRenderer spriteRenderer;
private RaycastHit2D raycastHit2D;

raycastHit2D = Physics2D.Raycast(transform.position, Vector2.right, 1);
	if (raycastHit2D.collider != null)
		spriteRenderer.flipX = !spriteRenderer.flipX;
```

```

    private float drawtime;
    
            drawtime = 0;

       
       if (Input.anyKey)
        {
            drawtime += Time.deltaTime;
            if (drawtime > 1)
            {
                audioSource.Play();
                drawtime = 0;
            }
        }
        else
        {
            drawtime = 10; //그리기 시작할때 잠시 들리지 않는것을 방지하기 위해
            Debug.Log(drawtime);
            audioSource.Stop();
        }
```

