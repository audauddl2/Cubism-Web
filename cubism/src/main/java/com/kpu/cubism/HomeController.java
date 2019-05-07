package com.kpu.cubism;

import java.text.DateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.kpu.cubism.service.MemoryService;
import com.kpu.cubism.vo.MemoryVo;

/**
 * Handles requests for the application home page.
 */
@Controller
public class HomeController {
	
	private static final Logger logger = LoggerFactory.getLogger(HomeController.class);
	
	@Autowired
	private MemoryService service;
	
	/**
	 * Simply selects the home view to render by returning its name.
	 */
	@RequestMapping(value = "/", method = RequestMethod.GET)
	public String home(Locale locale, Model model) {
		logger.info("Welcome home! The client locale is {}.", locale);
		
		Date date = new Date();
		DateFormat dateFormat = DateFormat.getDateTimeInstance(DateFormat.LONG, DateFormat.LONG, locale);
		
		String formattedDate = dateFormat.format(date);
		
		model.addAttribute("serverTime", formattedDate );
		
		return "/home/index";
	}
	/*
	 * 
	 * GET Controller 
	 * 
	 * 
	 */
	@RequestMapping(value = "/main", method = RequestMethod.GET)
	public String main(Locale locale, Model model) {
		
		
		return "/home/main";
	}
	@RequestMapping(value = "/chartview", method = RequestMethod.GET)
	public String chartview(Locale locale, Model model) {

		return "/chart/mychart";
	}
	
	@RequestMapping(value = "/upload", method = RequestMethod.GET)
	public String upload(Locale locale, Model model) {
		
		
		return "/upload/myupload";
	}
	@RequestMapping(value = "/uploadlisttest", method = RequestMethod.GET)
	public String uploadlist(ModelMap modelMap, @ModelAttribute MemoryVo vo, Locale locale, Model model) {
		
		List<MemoryVo> Memorylist = service.getMemoryList(vo);
		modelMap.addAttribute("list", Memorylist);
		
		return "/upload/myuploadlist";
	}
	@RequestMapping(value = "/calendar", method = RequestMethod.GET)
	public String calendar(Locale locale, Model model) {
		
		
		return "/calendar/mycalendar";
	}
	@RequestMapping(value="/access_denied_page")
    public String accessDeniedPage() throws Exception {
		
        return "/common/access_denied_page";
    }
	
	
	/* -----------------------------------------------------------
	 * 
	 * -------------------------Page Test------------------------- 
	 * 
	 * -----------------------------------------------------------
	 * 
	 * */
	

	
	/*
	 * GET Controller
	 * Header, Footer 
	 * 
	 */
	@RequestMapping(value = "/header", method = RequestMethod.GET)
	public String header(Locale locale, Model model) {
		
		
		return "/include/header";
	}
	
	@RequestMapping(value = "/footer", method = RequestMethod.GET)
	public String footer(Locale locale, Model model) {
		
		
		return "/include/footer";
	}
	
	
}
