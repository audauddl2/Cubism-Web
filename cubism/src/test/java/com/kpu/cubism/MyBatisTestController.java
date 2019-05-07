package com.kpu.cubism;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class MyBatisTestController {
	
	@Autowired
    private MyBatisTestService service;
    
    @RequestMapping("/selectNow.do")
    public void selectNow() {
        String result = service.selectNow();
        System.out.println(result);
    }   
	

}
