package com.kpu.cubism.controller;

import java.io.PrintWriter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.kpu.cubism.service.UserService;
import com.kpu.cubism.vo.UserVo;
import com.kpu.cubism.common.CommandMap;


@Controller
public class UserController {
	private static final Logger logger = LoggerFactory.getLogger(UserController.class);
	
	@Autowired
	UserService service;
	
	/* *****************************
	 * *                           *
	 * *       User GET            *
	 * *                           *
	 * *****************************
	 */
	
	/*
	 * 로그인 페이지 
	 */
	@RequestMapping(value = "/loginPage", method = RequestMethod.GET)
	public String LoginPage() throws Exception {
		return "/user/login";
	}
	
	/*
	 * 회원등록 페이지 
	 */
	@RequestMapping(value = "/registerPage", method = RequestMethod.GET)
	public String registertest() throws Exception {
		return "/user/register";
	}
	
	/* *****************************
	 * *                           *
	 * *       User POST            *
	 * *                           *
	 * *****************************
	 */
	
	/*
	 * 회원등록 
	 */
	@RequestMapping("/UserRegister")
	public String UserRegister(RedirectAttributes rttr, ModelMap modelMap, @ModelAttribute UserVo vo, HttpServletRequest request, HttpServletResponse response) throws Exception{
		PrintWriter out = response.getWriter();
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
	    response.setContentType("text/html;charset=UTF-8");
		
		
		//System.out.println("UserRegister Start =================================================");
		System.out.println("userName : " + request.getParameter("userName"));
		System.out.println("userSex : " + request.getParameter("userSex"));
		System.out.println("userId : " + request.getParameter("userId"));
		System.out.println("userPw : " + request.getParameter("userPw"));
		
			try {
				service.UserRegister(vo);
				System.out.println("등록 성공");
				
			}catch (Exception e) {
	            if (logger.isErrorEnabled()) {
	                logger.error(e.getMessage(), e);
	            }
	        }

			return "redirect:loginPage";
		}	
	/*
	 * 회원 중복 체크
	 */
	@RequestMapping(value = "/UserCheck", method = RequestMethod.POST)
	@ResponseBody
	public int UserCheck(CommandMap commandMap) throws Exception{

		//System.out.println("UserCheck Start =================================================");
	
		int checkResult = service.UserCheck(commandMap.getMap());
		
		return checkResult;
	}
	
	/* *****************************
	 * *                           *
	 * *       Security Test       *
	 * *                           *
	 * *****************************
	 */
	
	
	
}     