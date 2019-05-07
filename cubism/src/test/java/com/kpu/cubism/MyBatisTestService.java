package com.kpu.cubism;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class MyBatisTestService {

	    
	@Autowired
    private TestMapper mapper;
    
    public String selectNow() {
        return mapper.selectNow();
    }
}
