package com.kpu.cubism.service;

import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.kpu.cubism.common.UuidUtils;
import com.kpu.cubism.dao.UserDao;
import com.kpu.cubism.vo.UserVo;


@Service
public class UserService {
	
	@Autowired
	UserDao userDAO;
	
	@Autowired
	UuidUtils uuidUtils;
	
	/*
	 * 사용자 등록
	 * 
	 */
	public void UserRegister(UserVo vo) {
		// 사용자 키 생성
		vo.setUserKey(UuidUtils.getUuid());
		
		//System.out.println("----------UserDAO Start----------------");
		userDAO.UserRegister(vo);
		
	}
	/*
	 * 등록 조회
	 * 
	 */

	public int UserCheck(Map<String, Object> map) throws Exception {
		// TODO Auto-generated method stub
		return userDAO.UserCheck(map);
	}
	

}
